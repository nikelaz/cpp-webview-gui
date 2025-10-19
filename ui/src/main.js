import './style.css';

function main() {
  const textField = document.querySelector("#text-field");
  const sendBtn = document.querySelector("#send-btn");

  sendBtn.addEventListener("click", () => {
    window.ping(textField.value); 
  });
}

window.addEventListener('DOMContentLoaded', main);
