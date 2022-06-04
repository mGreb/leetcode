/*
 * 1114. Print in Order
 * Suppose we have a class:
 * public class Foo {
 *   public void first() { print("first"); }
 *   public void second() { print("second"); }
 *   public void third() { print("third"); }
 * }
 * The same instance of Foo will be passed to three different threads.
 * Thread A will call first(), thread B will call second(), and thread C will call third().
 * Design a mechanism and modify the program to ensure that second() is executed after first(),
 * and third() is executed after second().
 * Note:
 * We do not know how the threads will be scheduled in the operating system,
 * even though the numbers in the input seem to imply the ordering.
 * The input format you see is mainly to ensure our tests' comprehensiveness.
 * */

#include <future>
#include <mutex>
#include <iostream>
#include <functional>

void printFirst() {
    std::cout << "first";
}
void printSecond() {
    std::cout << "second";
}
void printThird() {
    std::cout << "third";
}

class Foo {
private:
    std::mutex m1;
    std::mutex m2;
public:
    Foo() {
        m1.lock();
        m2.lock();
    }

    void first(std::function<void()> printFirst) {
        printFirst();
        m1.unlock();
    }

    void second(std::function<void()> printSecond) {
        m1.lock();
        printSecond();
        m2.unlock();
        m1.unlock();
    }

    void third(std::function<void()> printThird) {
        m2.lock();
        printThird();
        m2.unlock();
    }
};

int main() {
    Foo f;
    std::function<void()> f1 = printFirst;
    std::function<void()> f2 = printSecond;
    std::function<void()> f3 = printThird;
    auto res2 = std::async(std::launch::async, &Foo::second, &f, f2);
    auto res1 = std::async(std::launch::async, &Foo::first, &f, f1);
    auto res3 = std::async(std::launch::async, &Foo::third, &f, f3);
    res3.get();
    res2.get();
    res1.get();
    return 0;
}
