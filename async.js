const fs =require ("fs");

const data = fs.readFileSync("read.txt","UTF-8");
console.log(data);


// asynchoronous


const dat = fs.readFile("read.txt","UTF-8" , (err,val) =>{
console.log(val);
});
console.log("You can do this ");