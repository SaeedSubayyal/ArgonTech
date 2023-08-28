const fs = require("fs");

 fs.writeFileSync("read.txt","Hello, Subayyal Saeed");
 const buff_data = fs.readFileSync("read.txt");
console.log(buff_data);