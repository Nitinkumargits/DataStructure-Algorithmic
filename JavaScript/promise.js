const p1 = Promise.resolve("First");
const p2 = Promise.resolve("Second");
const p3 = Promise.resolve("Third");

Promise.all([p1, p2, p3])
  .then((results) => console.log("All resolved:", results))
  .catch((error) => console.log("One failed:", error));
