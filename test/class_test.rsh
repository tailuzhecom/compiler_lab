class A {
    int a;
    int b;
};

int main() {
    A a;
    a.a = 1;
    a.b = 1;
    int c = a.a + a.b;
    printf("%d    ", c);
    return 0;
}
