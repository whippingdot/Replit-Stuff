const button = document.querySelector(".dark-light");
let buttonImg = document.querySelector(".themeChangeImage");
let themeChoosing = document.querySelector(".changeTheme");

// Pressing the dark and light mode toggle should change CSS files...Maybe make the CSS files first?
button.addEventListener("click", () => {
  console.log("It actually came in!");
  if (themeChoosing.getAttribute("href") == "./CSS/light.css") {
    themeChoosing.setAttribute("href", "./CSS/dark.css");
    buttonImg.setAttribute("src", "./Images/Sun.png");
  } else {
    themeChoosing.setAttribute("href", "./CSS/light.css");
    buttonImg.setAttribute("src", "./Images/Moon.png");
  }
  console.log("It went out!");
});
