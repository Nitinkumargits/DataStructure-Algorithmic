const func = async function () {
  try {
    const res = await axios.get("URL", (err) => {
      console.log(res.data);
    });
  } catch (error) {
    console.log(error);
  }
};
