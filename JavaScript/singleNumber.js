const singleNumbers = (nums) => {
  let xorAll = nums.reduce((acc, num) => acc ^ num, 0);
  let mask = xorAll & -xorAll;

  let [num1, num2] = [0, 0];
  for (let num of nums) {
    if (num & mask) num1 ^= num;
    else num2 ^= num;
  }
  return [num1, num2];
};

console.log("Single Numbers:", singleNumbers([1, 2, 1, 3, 2, 5]));
