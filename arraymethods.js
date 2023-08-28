const numbers = [65, 44, 12, 4];
const newArr = numbers.map(myFunction)

function myFunction(num) {
  return num * 10;
}


console.log(newArr);

const number1 = [10,2,31,43];
const newarray = number1.map(myfun1);

function myfun1(num){
return num * 20;
}
console.log(newarray);

// for each
const fruits = ['Apple', 'Banana', 'Lemon'];

fruits.forEach((str, index, array) => {
    array[index] = str + ' - Pakistan';
});

console.log(fruits);


const age = [12,3,51,12];
const ages18 = age.find(myfun3);
function myfun3(age){
 return age > 18; 
}

console.log(ages18);

//age.Each(myfun3);
const numbers2 = [75,42,22,1,1];
numbers2.forEach(myFunctions);
function myFunctions(items){
let sum;
sum = sum + items;
}

const ages = [3, 10, 18, 20];

function checkAdult(age) {
  return age > 18;
}


console.log(ages.some(checkAdult));


const numbers3 = [175, 50, 25];

console.log( numbers3.reduce(myFunc));

function myFunc(total, num) {
  return total - num;
}

const car = {type:"Fiat", model:"500", color:"white"};
// Ask for car name:
 console.log(car?.type);
