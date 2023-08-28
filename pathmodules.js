const path = require("path");


console.log(path.parse("./bio.txt/trent.txt"));
console.log(path.extname("./bio.txt/trent.txt"));
console.log(path.basename("./bio.txt/trent.txt"));
console.log(path.toNamespacedPath("./bio.txt/trent.txt"));
console.log(path.dirname("./bio.txt/trent.txt"));