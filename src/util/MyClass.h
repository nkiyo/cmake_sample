class MyClass {
 public:
  int getX() { return x_; };
  void setX(int x, int *y);

 private:
  int x_;
  double y_;

 public:
  int myFunc(int);
};
