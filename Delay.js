const sleep = (delay) => {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(delay * 1000);
        }, delay * 1000);
    });
};

const printer = async () => {
    const textToShow = ["I am the first line in this text",
        "I am the second line after 1 second",
        "I am the third line after 2 seconds"];

    // Delay will NOT work in this case becaue of callback creating seprate threads for each call to the function, and the delay will work for each thread seperately, resulting in NOT producing the delay effect

    // textToShow.forEach(async (element) => {
    //     const delay = await sleep(3);
    //     console.log(element);
    // });

    const delay = await sleep(1);
    for (let index = 0; index < textToShow.length; index++) {
        const element = textToShow[index];
        console.log(element);
        const delay = await sleep(1);
    }

    return "Successfully Executed...";
}

console.log("This is a printer with the use of promises as delay");
printer().then((value) => {
    console.log(value);
});