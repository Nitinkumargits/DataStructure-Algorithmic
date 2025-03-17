const removeDuplicates = {
  unique: function (arr) {
    if (arr.length == 0) return;

    let j = 0;
    for (let i = 1; i < arr.length; i++) {
      if (arr[i] !== arr[j]) {
        j++;
        arr[j] = arr[i];
      }
    }
    return j + 1;
  },
};

let arr = [1, 1, 2, 2, 3, 4, 4, 5];
let newSize = removeDuplicates.unique(arr);

console.log("New array:", arr.slice(0, newSize));
console.log("New length:", newSize);
