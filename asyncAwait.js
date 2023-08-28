// Async/Await
async function text(){
    console.log('1: Message')
    await console.log('2: Message')
    console.log('3: Message')
    console.log('4: Message')
}
console.log('5: Message')
console.log('6: Message')
text()
console.log('7: Message')
console.log('8: Message')

async function myFunction() {return "Hello";}

myFunction().then(
  function(value) {myDisplayer(value);},
  function(error) {myDisplayer(error);}
);