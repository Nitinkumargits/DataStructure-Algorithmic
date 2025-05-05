const getDocPic = () => {
  return new Promise((resolve, _) => {
    resolve("GET pic");
  });
};

// let x = getDocPic().then((res) => console.log(res));

(async () => {
  const x = await getDocPic();
  console.log(x);
})();
