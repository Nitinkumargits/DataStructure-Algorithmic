function printLeaders(arr, size) {
  for (let i = 0; i < size; i++) {
    let j;
    for (j = i + 1; j < size; j++) {
      if (arr[i] <= arr[j]) break;
    }
    if (j == size) document.write(arr[i] + " ");
  }
}

let arr = [16, 17, 4, 3, 5, 2];
let n = arr.length;

// Function calling
printLeaders(arr, n);
