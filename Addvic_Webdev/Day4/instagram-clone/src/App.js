import "./App.css";
import Header from "./components/Header/Header";
import MainArea from "./components/MainArea/MainArea";
import Sidebar from "./components/Sidebar/Sidebar";

const App = () => {
  return (
    <div>
      <Header />
        <div className="appBody">
        <MainArea />
        <Sidebar />
        </div>
    </div>
  )
};
export default App