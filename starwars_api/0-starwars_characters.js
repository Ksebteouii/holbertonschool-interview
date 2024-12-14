#!/usr/bin/node
// Script to fetch Star Wars characters using the Star Wars API

const request = require('request');

// Command-line argument for film ID
const FILMID = process.argv[2];

// Base URL of the Star Wars API
const URL_BASE = 'https://swapi-api.hbtn.io/api/films';

// Function to make HTTP requests using Promises
function doRequest (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, res, body) => {
      if (!error && res.statusCode === 200) {
        resolve(JSON.parse(body));
      } else {
        reject(error || `Status Code: ${res.statusCode}`);
      }
    });
  });
}

// Main function to fetch characters of a film
async function main (filmID) {
  if (!filmID) {
    console.error('Usage: ./script.js <filmID>');
    return;
  }

  try {
    const res = await doRequest(`${URL_BASE}/${filmID}`);
    for (const e of res.characters) {
      const pj = await doRequest(e);
      console.log(pj.name);
    }
  } catch (error) {
    console.error('Error:', error);
  }
}

// Execute the script
main(FILMID);