const host ="0.0.0.0";
const port =6001;
const http  = require ("http");
const fs = require ("fs");
const server = http.createServer((req,res)=>{
    // console.log(req.url)
    if (req.url === "/demo"){
       // res.end("Hello From Demo");

        fs.readFile("userapi.json","utf-8", (err,data)=>{
            console.log(data);
            res.end(data);
            res.writeHead(200,{"Content-type": "application/json"});
            //res.writeHead(400,{"Content-type": "application/json"});

        });
    }
    if (req.url === "/contact"){
     res.end("Hello From Contact");
    }
});
server.on("error", (error) => {
    console.error("Server error:", error);
});
server.listen(port,host,()=>{
    console.log(`Listening on Port ${port}` );
});