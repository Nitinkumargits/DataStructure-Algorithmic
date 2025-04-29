const API_URL = "https://forkify-api.herokuapp.com/api/v2/recipes/";

const showRecipe = async function () {
  try {
    const res = await fetch("https://forkify-api.herokuapp.com/api/v2/recipes");

    if (!res.ok) throw new Error(`${res.status} ${res.statusText} 💔`);

    const data = await res.json();
    console.log("data :", data);
  } catch (error) {
    console.log("ERROR : ", error);
  }
};

let arrayInterger3 = [1, 2, 3, 4, 5];
let arrayInterger2 = [1, 2, 3, 4, 5];
// showRecipe();
// /////////////////////////////

let arrayInterger = [1, 2, 3, 4, 5];

console.log("Original arry : Before :", arrayInterger); //Original arry : Before : [ 1, 2, 3, 4, 5 ]

let arrayIntergerS = arrayInterger.splice(3, 1, "a", "b", "c");

console.log("Spliced ", arrayIntergerS); ////Spliced  [ 4 ]

console.log("Original arry : After :", arrayInterger); //Original arry : After : [ 1,   2,   3, 'a','b', 'c', 5 ]

// let arrayIntergerS2 = arrayInterger1.splice(3);
// let arrayIntergerS3 = arrayInterger1.splice(3, 1, "a", "b", "c");

// console.log(arrayIntergerS2);
// console.log(arrayIntergerS3);

////////////////////////////////////////////////////////////////////

<script></script>;
