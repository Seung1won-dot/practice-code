// Promise와 async/await

// Promise
const promise = new Promise((resolve, reject) => {
  setTimeout(() => resolve("완료"), 1000);
});

promise
  .then(result => console.log(result))
  .catch(err => console.error(err))
  .finally(() => console.log("종료"));

// async/await
async function fetchData() {
  try {
    const response = await fetch("https://api.example.com/data");
    const data = await response.json();
    return data;
  } catch (error) {
    console.error("에러:", error);
  }
}
