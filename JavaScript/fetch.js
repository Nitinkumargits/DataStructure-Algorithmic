const showRecipe = async function () {
  try {
    const res = await fetch(
      `https://forkiy-api.com.herokuapp.com/api/v2/recipes/534ed66`
    );

    const data = await res.json();
    console.log(data);
  } catch (error) {
    console.log(error);
  }
};
