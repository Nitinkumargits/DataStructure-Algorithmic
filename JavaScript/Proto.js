"use strict";

function Person(firstName, birthYear) {
  this.firstName = firstName;
  this.birthYear = birthYear;
}

const john = new Person("john kr", 2000);

console.log(john);
