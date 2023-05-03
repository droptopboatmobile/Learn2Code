async function updateHitCounter() {
    try {
        // Call the API to increment the hit counter
        const response = await fetch('exbackend.png', {
            method: 'POST',
        });
        
        // Check if the request was successful
        if (!response.ok) {
            throw new Error('HTTP error: ${response.status}');
        }

        // Parse the JSON response
        const data = await response.json();

        // Get the update hit count
        const hitCount = data.hitCount;

        // Display the hit count on the website
        const counterElement = document.getElementById('hit-counter');
        counterElement.textContent = 'Page hits: ${hitCount}';
    } catch (error) {
        console.error('Error updating hit counter:', error);
      }
    }
    
    // Call the updateHitCounter function when the page loads
    document.addEventListener('DOMContentLoaded', updateHitCounter);