"use strict";

function invertBit(num) {
  let x = parseInt(Math.log(num) / Math.log(2)) + 1;

  //invert the bit
  for (let i = 0; i < x; i++) {
    num = num ^ (1 << i);
    document.write(num);
  }
}

let num = 11;
invertBit(num);
