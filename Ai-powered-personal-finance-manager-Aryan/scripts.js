document.addEventListener("DOMContentLoaded", function () {
    const dashboard = document.getElementById("dashboard");
  
    // Handle navigation clicks
    document.getElementById("salary").addEventListener("click", function () {
      updateDashboard("Salary Details", "Basic: $50,000", "Bonus: $5,000", "Total: $55,000");
    });
  
    document.getElementById("transactions").addEventListener("click", function () {
      updateDashboard("Recent Transactions", "Amazon Purchase: -$100", "Salary Credit: +$5,000", "Netflix: -$15");
    });
  
    document.getElementById("investment").addEventListener("click", function () {
      updateDashboard("Investment Portfolio", "Stocks: $20,000", "Crypto: $5,000", "Mutual Funds: $10,000");
    });
  
    document.getElementById("tax-status").addEventListener("click", function () {
      updateDashboard("Tax Status", "Paid: $3,000", "Pending: $500", "Deductions: $1,200");
    });
  
    function updateDashboard(title, item1, item2, item3) {
      dashboard.innerHTML = `
        <div class="card">
          <h3>${title}</h3>
          <p>${item1}</p>
          <p>${item2}</p>
          <p>${item3}</p>
        </div>
      `;
    }
  
    //---------------chatbot---------------------
    const chatbotIcon = document.getElementById("chatbotIcon");
  
    let isDragging = false;
    let offsetX, offsetY;
  
    chatbotIcon.addEventListener("mousedown", (e) => {
      isDragging = true;
      offsetX = e.clientX - chatbotIcon.getBoundingClientRect().left;
      offsetY = e.clientY - chatbotIcon.getBoundingClientRect().top;
      chatbotIcon.style.cursor = "grabbing";
    });
  
    document.addEventListener("mousemove", (e) => {
      if (!isDragging) return;
      const x = e.clientX - offsetX;
      const y = e.clientY - offsetY;
      chatbotIcon.style.left = `${x}px`;
      chatbotIcon.style.top = `${y}px`;
      chatbotIcon.style.position = "absolute";
    });
  
    document.addEventListener("mouseup", () => {
      isDragging = false;
      chatbotIcon.style.cursor = "grab";
    });
  });
  