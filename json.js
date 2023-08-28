const fs  = require("fs");
const biodata = {
name: "Subayyal Saeed",
age: 20,
Place: "Lahore",
University: "Stanford and Fast Nuces"
};

const Jsondata = JSON.stringify(biodata);
const Jsonobj = JSON.parse(Jsondata);

fs.writeFile("Json1.json",Jsondata,(err)=>{
    console.log("Done");
});
fs.readFile("Json1.json","utf-8", (err,data)=>{
   const orgdata = JSON.parse(data);
    console.log(orgdata);
});

