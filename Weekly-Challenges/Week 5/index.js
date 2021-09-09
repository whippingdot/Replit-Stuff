const express = require("express");
const app = express();

app.use("favicon.ico", express.static("./favicon.ico"));

app.get("/", async (_, res) => {
  console.log("[DEBUG] Entered home page");
  res.sendFile("./index.html");
});
app.get("/style", async (_, res) => {
  console.log("[DEBUG] Picked up the CSS file");
  res.sendFile("./style.css");
});
app.get("/windowsImage", async (_, res) => {
  console.log("[DEBUG] Got the image");
  res.sendFile("./Windows11logo.png");
});
app.listen(8080, () => {
  console.log("Listening on port 8080");
});
