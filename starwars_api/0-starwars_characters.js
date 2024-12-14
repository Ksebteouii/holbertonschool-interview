#!/usr/bin/node
// Prints all characters of a Star Wars movie in order

const request = require('request');
// Your script logic here
const FILM_ID = process.argv[2];
const API_URL = `https://swapi-api.hbtn.io/api/films/${FILM_ID}/`;

// Ensure a valid movie ID is provided
if (!FILM_ID) {
  console.error('Usage: ./0-starwars_characters.js <Movie ID>');
  process.exit(1);
}

request(API_URL, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  const film = JSON.parse(body);
  const characterUrls = film.characters;

  // Fetch character names in order
  const fetchCharacter = (url) =>
    new Promise((resolve, reject) => {
      request(url, (error, response, body) => {
        if (error) {
          reject(error);
        } else {
          resolve(JSON.parse(body).name);
        }
      });
    });

  // Process all character URLs sequentially to ensure proper order
  (async () => {
    try {
      for (const url of characterUrls) {
        const characterName = await fetchCharacter(url);
        console.log(characterName);
      }
    } catch (err) {
      console.error(err);
    }
  })();
});
