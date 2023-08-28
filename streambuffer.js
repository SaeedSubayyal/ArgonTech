const fs = require("fs");
const http = require("http");
const server = http.createServer();

server.on("request", (req, res) => {
    const rstream = fs.createReadStream("input.txt");
    rstream.pipe(res);
    
    // rstream.on("data", (dataChunk) => {
    //     res.write(dataChunk);
    // });

    // rstream.on("end", () => {
    //     res.end();
    // });

    // rstream.on("error", (err) => {
    //     console.error(err);
    //     res.writeHead(404, { 'Content-Type': 'text/plain' });
    //     res.end("File not Found");
    // });
});

server.listen(6002, "127.0.0.1", () => {
    console.log('Server is listening on http://127.0.0.1:6002');
});
