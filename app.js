const express = require('express');
const axios = require('axios');
const sqlite3 = require('sqlite3').verbose();

const app = express();
const PORT = process.env.PORT || 3000;

// Set up SQLite database
const db = new sqlite3.Database('stories.db');

// Create a table for storing stories
db.run(`
  CREATE TABLE IF NOT EXISTS stories (
    id INTEGER PRIMARY KEY,
    title TEXT,
    url TEXT
  )
`);

// Fetch top stories from the Hacker News API and store them in the database
axios.get('https://hacker-news.firebaseio.com/v0/topstories.json')
  .then(response => {
    const topStoryIds = response.data.slice(0, 10); // Fetch top 10 stories

    topStoryIds.forEach(storyId => {
      axios.get(`https://hacker-news.firebaseio.com/v0/item/${storyId}.json`)
        .then(storyResponse => {
          const { title, url } = storyResponse.data;
          db.run('INSERT INTO stories (title, url) VALUES (?, ?)', [title, url]);
        })
        .catch(error => {
          console.error('Error fetching story:', error);
        });
    });
  })
  .catch(error => {
    console.error('Error fetching top stories:', error);
  });

// Set up Express
app.set('view engine', 'ejs');
app.use(express.static('public'));

app.get('/', (req, res) => {
  db.all('SELECT * FROM stories', (err, stories) => {
    if (err) {
      console.error('Error retrieving stories from database:', err);
      res.status(500).send('Internal Server Error');
    } else {
      res.render('index', { stories });
    }
  });
});

app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
