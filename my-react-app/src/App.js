import './App.css';
import Home from './pages/Home';
import User from './pages/User';
import {BrowserRouter, Route, Routes} from "react-router-dom";

function App() {
  return (
    <div>
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/User" element={<User />} />
      </Routes>
    </BrowserRouter>
    </div>
  );
}

export default App;