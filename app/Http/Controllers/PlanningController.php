<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Planning; // Zorg ervoor dat je het model importeert

class PlanningController extends Controller
{
    /**
     * Display the current planning.
     *
     * @return \Illuminate\Http\Response
     */
    public function show()
    {
        $planning = Planning::latest()->first();
        return response()->json(['planning' => $planning]);
    }
    

    /**
     * Update the current planning.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request)
    {
        $request->validate([
            'content' => 'required', // Valideer dat inhoud is ingevuld
        ]);
    
        $planning = Planning::latest()->first() ?? new Planning;
        $planning->content = $request->input('content');
        $planning->save();
    
        return response()->json(['success' => true, 'message' => 'Planning updated successfully!']);
    }
    
}
