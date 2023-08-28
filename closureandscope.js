function myFunction() {
    let a = 4;
    return a * a;
  }
  let a = myFunction();
  console.log(a);



  let b = 4;
function myFunction1() {
  return b * b;
}
let m = myFunction1();
console.log(m);

// function inside a function  is also closure
function add() {
    let counter = 0;
    function plus() {counter += 1;}
    plus();   
    return counter;
  }
//  

let passed = 6;
function addto(){
let inner = 5;
return (passed*inner);
}

console.log(addto());
//---------------------------------

// block scope function scope and global scope

