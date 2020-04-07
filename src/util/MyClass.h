#ifndef _HOME_NKIYO_CMAKE_SAMPLE_SRC_UTIL_MYCLASS_H
#define _HOME_NKIYO_CMAKE_SAMPLE_SRC_UTIL_MYCLASS_H

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

#endif
