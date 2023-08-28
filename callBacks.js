// Call Back
function add(a,b,callBack){
    x = a + b
    callBack(x)
}
function display(x){
    console.log(x)
}
add(4,5,display)