import * as React from "react";
import * as ReactDOM from "react-dom";
import App from "../components/app/script";
import "./style.scss";

window.onload = () => {
    ReactDOM.render(<App/>, document.getElementById('root'));
};
