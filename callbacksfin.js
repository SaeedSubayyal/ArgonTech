
function myDisplayer(some) {
    document.getElementById("demo").innerHTML = some;
  }
  
  function myFirst() {
    myDisplayer("Hello");
  }
  
  function mySecond() {
    myDisplayer("Goodbye");
  }
  
  myFirst();
  mySecond();
  
  function greet(name, callback) {
    console.log('Hi' + ' ' + name);
    callback();
  }
  
  function callMe() {
    console.log('I am callback function');
  }
  
  greet('Peter', callMe);