const ArrayOperations = {
  leftRotate: function (arr, d) {
    let n = arr.length;
    d = d % n; // Handle cases where d > n
    let rotatedArr = arr.slice(d).concat(arr.slice(0, d)); //
    return rotatedArr;
  },
  printArray: function (arr) {
    console.log("Rotated Array:", arr);
  },
};
let arr = [1, 2, 3, 4, 5];
let d = 3;
let rotatedArr = ArrayOperations.leftRotate(arr, d);
ArrayOperations.printArray(rotatedArr);
