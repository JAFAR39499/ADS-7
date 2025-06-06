// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_
#include <cstdint>

class Train {
 private:
  struct Car {
    bool light; // состояние лампочки
    Car* next;
    Car* prev;
    explicit Car(bool l = false) : light(l), next(this), prev(this) {}
  };
  int countOp; // счетчик шагов (число переходов из вагона в вагон)
  Car* first; // точка входа в поезд (первый вагон)
 public:
  Train();
  ~Train();
  void addCar(bool light); // добавить вагон с начальным состоянием лампочки
  int getLength();          // вычислить длину поезда
  int getOpCount() const { return countOp; }// вернуть число переходов
};
#endif  // INCLUDE_TRAIN_H_
