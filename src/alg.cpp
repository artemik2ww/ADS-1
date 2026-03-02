// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2){
    return false;
  }
  for (uint64_t i = 2; i*i <= value;i++){
    if (value % i == 0){
      return false;
    }
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t k = 0;
  if (n == 0){
    return 0;
  }
  for (uint64_t i = 2 ; ; i++){
    if (checkPrime(i)){
      k++;
      if (k == i){
        return i;
      }
    }
  }
  return k;
}

uint64_t nextPrime(uint64_t value) {
  if ( value == 18446744073709551615){ return value; }
  for (uint64_t i = value + 1; i <= 18446744073709551615; i++){
    if (checkPrime(i)){
      return i;
    }
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t k = 0;
  for (uint64_t i = 2; i < hbound; i++){
    if (checkPrime(i)){
      k+=i;
    }
  }
  return k;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t k = 0;
  for (uint64_t i = lbound; i < hbound- 2; i++){
    if (checkPrime(i) && checkPrime(i+2)){
      k++;
    }
  }
  return k;
}
