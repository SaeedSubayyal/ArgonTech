

function myfuc1(firstname, lastname){

    return firstname+lastname;
}

let falsetest = myfuc1();
let y = myfuc1("subayyal","saeed");

console.log(y);

function raisealert(){

    alert("Hey Alerted");
}

function toCelsius(fahrenheit) {
    return (5/9) * (fahrenheit-32);
  } 
// testing builtin 
let x = toCelsius(77);
let text = "The temperature is " + x + " Celsius";