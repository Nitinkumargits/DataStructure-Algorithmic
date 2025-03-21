const mergeSortedArrays = (arr1, arr2) => {
  let i = arr1.length - 1,
    j = 0;

  while (i >= 0 && j < arr2.length) {
    if (arr1[i] > arr2[j]) {
      [arr1[i], arr2[j]] = [arr2[j], arr1[i]];
    }
    i--;
    j++;
  }
  arr1.sort((a, b) => a - b);
  arr2.sort((a, b) => a - b);
};

let arr1 = [1, 3, 5, 7];
let arr2 = [2, 4, 6, 8];

mergeSortedArrays(arr1, arr2);

console.log(arr1);
console.log(arr2);
