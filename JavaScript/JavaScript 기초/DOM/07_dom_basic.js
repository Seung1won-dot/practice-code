// DOM 조작 기본

// 요소 선택
const el = document.getElementById("myId");
const els = document.querySelectorAll(".myClass");
const one = document.querySelector(".myClass");

// 요소 생성
const div = document.createElement("div");
div.textContent = "새 요소";
div.className = "box";

// DOM에 추가
document.body.appendChild(div);

// 부모에 삽입
parent.insertBefore(div, referenceNode);

// 제거
div.remove();

// 속성
div.setAttribute("data-id", "1");
div.getAttribute("data-id");
div.classList.add("active");
div.classList.remove("active");
div.classList.toggle("active");
