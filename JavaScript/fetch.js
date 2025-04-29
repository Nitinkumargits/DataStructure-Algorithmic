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

showRecipe();
