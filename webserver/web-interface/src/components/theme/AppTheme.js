import { createTheme } from '@mui/material';

const lightTheme = createTheme({
  palette: {
    mode: 'light',
    primary: {
      main: '#ef4e2b',
    },
    secondary: {
      main: '#0288d1',
    },
    appbar: {
      main: '#272727',
    },
    background: {
      default: '#F5F5F5',
      paper: '#FFF',
    },
    temperature: {
      main: '#ef4040',
    },
    flow: {
      main: '#ff9d00',
    },
    weightFlow: {
      main: '#1d7835',
    },
    pressure: {
      main: '#6296C5',
    },
    weight: {
      main: '#844B48',
    },
  },
});

const darkTheme = createTheme({
  palette: {
    mode: 'dark',
    primary: {
      main: '#ef4e2b',
    },
    secondary: {
      main: '#0288d1',
    },
    temperature: {
      main: '#ef4040',
    },
    flow: {
      main: '#ffb53e',
    },
    weightFlow: {
      main: '#1d7835',
    },
    pressure: {
      main: '#6296C5',
    },
    weight: {
      main: '#a75c58',
    },
    background: {
      default: '#111',
      paper: '#111',
    },
  },
});

export default function getAppTheme(mode) {
  return (mode === 'light') ? lightTheme : darkTheme;
}
