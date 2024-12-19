import React, { useState } from 'react';

function transInputs() {
    const [rpm, setRpm] = useState('');
    const [spd, setSpd] = useState('');

    // 
    const handleShiftUp = () => {
        alert('Shifted up 1');
        // Add reference to gear shifted to
    };
    const handleShiftDown = () => {
        alert('Shifted down 1');
        // Add reference to gear shifted to
    };
    const handleLSTup = () => {
        alert('LST up');
        // Incomplete, call backend for gear change
    };
    const handleLSTdown = () => {
        alert('LST down');
        // Incomplete, call backend for gear change
    };

    return (
        <div style={{
            display: 'flex',
            flexDirection: 'column',
            alignItems: 'center',
            justifyContent: 'center',
            height: '100%',
            backgroundColor: '#E3B80F'
        }}>
            <h1>Koenigsegg Jesko LST</h1>

            <div style={{marginBottom: '20px'}}>
                <input
                    name='Rpm Input'
                    type='number'
                    placeholder='Enter RPMs'
                    value={rpm}
                    onChange={(e) => setRpm(e.target.value)}
                    style={{marginRight: '10px', padding: '10px', width: '200px'}}
                />
                <input
                    name='Speed Input'
                    type='number'
                    placeholder='Enter Speed'
                    value={spd}
                    onChange={(e) => setSpd(e.target.value)}
                    style={{padding: '10px', width: '200px'}}
                />
            </div>
        </div>
    );
}