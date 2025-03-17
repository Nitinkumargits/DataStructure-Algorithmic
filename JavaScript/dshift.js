function leftrotate(arr, d) {
  d = d % arr.length;
  let temp = arr.slice(0, d);
  arr.splice(0, d);
  arr.push(...temp);
}

let arr = [1, 2, 3, 4, 5];
let d = 2;

leftrotate(arr, d);
console.log(arr);
