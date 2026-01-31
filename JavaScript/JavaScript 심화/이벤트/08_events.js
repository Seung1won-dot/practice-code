// 이벤트 처리

// addEventListener
const btn = document.querySelector("button");
btn.addEventListener("click", function(event) {
  console.log("클릭됨", event.target);
});

// 화살표 함수 (this 주의)
btn.addEventListener("click", (e) => {
  e.preventDefault();  // 기본 동작 막기
  e.stopPropagation();  // 버블링 막기
});

// 이벤트 위임
document.getElementById("list").addEventListener("click", (e) => {
  if (e.target.matches("li")) {
    console.log("li 클릭:", e.target.textContent);
  }
});

// 자주 쓰는 이벤트
// click, dblclick, keydown, keyup, submit, load, scroll, resize
