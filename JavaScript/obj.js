const txt = '{"name":"John", "age":30, "city":"New York"}';
const obj = JSON.parse(txt);
console.log(obj);

console.log(JSON.stringify(obj));

const text = '[ "Ford", "BMW", "Audi", "Fiat" ]';
const myArr = JSON.parse(text);
console.log(myArr);
