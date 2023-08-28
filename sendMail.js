// sendMail.js
const nodemailerX = require("nodemailer"); 

const sendMail = async (req, res) => {
    let testaccount = await nodemailerX.createTestAccount();
    const transporter = nodemailerX.createTransport({
        host: "smtp.ethereal.email",
        port: 587,
        auth: {
          // TODO: replace `user` and `pass` values from <https://forwardemail.net>
          user: 'jalon.russel@ethereal.email',
          pass: 'HcuKh7SEYQ5MsC2KR6'
        }
      });
      let info = await transporter.sendMail({
        from: '"Jalon Russel" <jalon.russel@ethereal.email>', // sender address
        to: "subayyalsaeed321@gmail.com", // list of receivers
        subject: "Testing API", // Subject line
        text: "Hi, Its nice to meet you. How aRE YOU MOUZ", // plain text body
        html: "<b>Hi, Its nice to meet you.MOUZ Is</b>", // html body
      });
      console.log("Message Sent: %s",info.messageId);
      res.json(info);
    res.send("I am sending MAIL");
};

module.exports = sendMail;
