

const fs = require ("fs");

fs.mkdir("bio.txt", err =>{
console.log("File is created");
});

fs.writeFile("./bio.txt/trent.txt","Subayyal Ismail Saeed",err=>{
console.log("Written succesfully");
});

fs.appendFile("./bio.txt/trent.txt","Subayyal Ismail Saeed",err=>{
    console.log("DATA HAS BEEN APPENDE");
    });

fs.readFile("./bio.txt/trent.txt",'utf-8',(err,data2) =>{
    console.log(data2);
});

fs.rename("./bio.txt/trent.txt","./bio.txt/trion.txt", (err) =>{
    console.log("Renamed");
});