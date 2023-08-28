// nodemailer.js
const express = require("express");
const app = express();

const sendMail = require("./sendMail"); // Relative path to sendMail.js

app.get("/", (req, res) => {
    res.send("I am a Server");
});

app.get("/sendmail", sendMail);

const start = async () => {
    try {
        app.listen(6002, () => {
            console.log("Server is listening on Port 6002");
        });
    } catch (error) {
        console.error("An error occurred:", error.message);
    }
};

start();
