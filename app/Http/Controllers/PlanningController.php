<?php

namespace App\Http\Controllers;

use App\Models\Planning;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;


class PlanningController extends Controller
{
    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     * 
     */

     public function show()
     {
         // Haal de laatst toegevoegde planning op
         $planning = Planning::latest()->first();
     
         // Stuur de planning door naar de view
         return view('planning.show', compact('planning'));
     }

     public function index()
     {
         $plannings = Planning::select('plannings.*')
             ->join(
                 DB::raw("(SELECT MAX(id) as id FROM plannings GROUP BY content) latest"),
                 'latest.id', '=', 'plannings.id'
             )
             ->orderBy('created_at', 'desc')
             ->get();
     
         return view('page1', compact('plannings')); // Vervang 'your_view_name' door de juiste view-naam
     }

     public function replicate($id)
     {
         $original = Planning::find($id);
         if ($original) {
             $newPlanning = $original->replicate();
             $newPlanning->save();
             return response()->json(['success' => true, 'message' => 'Planning succesvol opnieuw gepubliceerd']);
         }
         return response()->json(['success' => false, 'message' => 'Planning niet gevonden'], 404);
     }

     public function store(Request $request)
     {
         $request->validate(['content' => 'required']);
     
         $planning = new Planning();
         $planning->content = $request->content;
         $planning->save();
     
         return response()->json(['success' => true, 'message' => 'Planning succesvol opgeslagen!']);
     }
     

     public function destroy($id)
     {
         $planning = Planning::find($id);
         if ($planning) {
             // Verzamel alle berichten met dezelfde content
             $sameContentPlannings = Planning::where('content', $planning->content)->get();
     
             // Verwijder alle berichten met dezelfde content
             foreach ($sameContentPlannings as $item) {
                 $item->delete();
             }
     
             return response()->json(['success' => true, 'message' => 'Alle berichten met dezelfde inhoud zijn verwijderd']);
         }
         return response()->json(['success' => false, 'message' => 'Planning niet gevonden'], 404);
     }
}
